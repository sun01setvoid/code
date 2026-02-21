#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PARKING_SPOTS 10  // 停车场最大容量
#define PRICE_PER_MINUTE 1.0  // 每分钟收费

// 车辆信息结构
typedef struct {
    char license[20];     // 车牌号
    time_t entry_time;    // 进入时间
    int position;         // 在停车场中的位置（从1开始）
} Car;

// 顺序栈实现停车场
typedef struct {
    Car cars[MAX_PARKING_SPOTS];  // 车辆数组
    int top;                       // 栈顶指针
    int capacity;                  // 停车场容量
} ParkingLot;

// 队列节点
typedef struct QueueNode {
    Car car;
    struct QueueNode* next;
} QueueNode;

// 链式队列实现便道
typedef struct {
    QueueNode* front;  // 队头
    QueueNode* rear;   // 队尾
    int count;         // 车辆数量
} WaitingQueue;

// 函数声明
void initParkingLot(ParkingLot* lot, int capacity);
void initWaitingQueue(WaitingQueue* queue);
int isParkingLotFull(ParkingLot* lot);
int isParkingLotEmpty(ParkingLot* lot);
int isWaitingQueueEmpty(WaitingQueue* queue);
int parkCar(ParkingLot* lot, WaitingQueue* queue, char* license);
int leaveParkingLot(ParkingLot* lot, WaitingQueue* queue, int position, time_t leave_time);
int leaveWaitingQueue(WaitingQueue* queue, char* license);
void displayParkingStatus(ParkingLot* lot, WaitingQueue* queue);
void displayTimeInfo(time_t time);
double calculateFee(time_t entry_time, time_t leave_time);
void clearScreen();

int main() {
    ParkingLot parkingLot;
    WaitingQueue waitingQueue;
    int choice;
    int capacity = MAX_PARKING_SPOTS;
    char license[20];
    int position;
    time_t current_time;
    struct tm time_input;
    int year, month, day, hour, minute;
    
    // 初始化停车场和便道
    initParkingLot(&parkingLot, capacity);
    initWaitingQueue(&waitingQueue);
    
    do {
        clearScreen();
        printf("欢迎使用停车场管理系统\n\n");
        printf("请选择您需要进行的操作：\n");
        printf("1、查看停车场车辆数量\n");
        printf("2、查看便道的车辆数量\n");
        printf("3、进入停车场\n");
        printf("4、离开停车场\n");
        printf("5、离开停车场便道\n");
        printf("6、退出程序\n");
        printf("收费标准：本停车场按照%.2f元/分钟计费\n\n", PRICE_PER_MINUTE);
        printf("请输入您的选择：");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:  // 查看停车场车辆数量
                clearScreen();
                printf("=== 停车场车辆数量 ===\n");
                printf("停车场最大容量：%d\n", parkingLot.capacity);
                printf("当前停车数量：%d\n", parkingLot.top + 1);
                printf("剩余车位：%d\n", parkingLot.capacity - (parkingLot.top + 1));
                printf("\n按回车键返回主菜单...");
                getchar(); getchar();
                break;
                
            case 2:  // 查看便道车辆数量
                clearScreen();
                printf("=== 便道车辆数量 ===\n");
                printf("当前便道等候车辆：%d\n", waitingQueue.count);
                printf("\n按回车键返回主菜单...");
                getchar(); getchar();
                break;
                
            case 3:  // 车辆进入停车场
                clearScreen();
                printf("=== 车辆进入停车场 ===\n");
                if (isParkingLotFull(&parkingLot)) {
                    printf("提示：停车场已满，车辆将进入便道等候\n");
                }
                printf("请输入车牌号：");
                scanf("%s", license);
                printf("请选择输入时间方式：\n");
                printf("1、使用当前系统时间\n");
                printf("2、手动输入时间\n");
                printf("请选择：");
                int time_choice;
                scanf("%d", &time_choice);
                if (time_choice == 1) {
                    current_time = time(NULL);
                } else {
                    printf("请输入进入时间（年 月 日 时 分）：");
                    scanf("%d %d %d %d %d", &year, &month, &day, &hour, &minute);
                    time_input.tm_year = year - 1900;
                    time_input.tm_mon = month - 1;
                    time_input.tm_mday = day;
                    time_input.tm_hour = hour;
                    time_input.tm_min = minute;
                    time_input.tm_sec = 0;
                    time_input.tm_isdst = -1;
                    current_time = mktime(&time_input);
                }
                if (parkCar(&parkingLot, &waitingQueue, license)) {
                    if (parkingLot.top >= 0) {
                        parkingLot.cars[parkingLot.top].entry_time = current_time;
                        printf("\n=== 车辆进入信息 ===\n");
                        printf("车牌号码：%s\n", license);
                        printf("停车位置：%d\n", parkingLot.top + 1);
                        printf("进入时间：");
                        displayTimeInfo(current_time);
                        printf("\n");
                    }
                }
                printf("\n按回车键返回主菜单...");
                getchar(); getchar();
                break;
                
            case 4: //车辆离开停车场
                clearScreen();
                printf("=== 车辆离开停车场 ===\n");
                if (isParkingLotEmpty(&parkingLot)) {
                    printf("停车场为空，没有车辆可以离开！\n");
                } else {
                    printf("请输入车辆在停车场的位置（1-%d）：", parkingLot.top + 1);
                    scanf("%d", &position);
                    if (position < 1 || position > parkingLot.top + 1) {
                        printf("位置无效！\n");
                    } else {
                        printf("请选择输入时间方式：\n");
                        printf("1、使用当前系统时间\n");
                        printf("2、手动输入时间\n");
                        printf("请选择：");
                        scanf("%d", &time_choice);
                        if (time_choice == 1) {
                            current_time = time(NULL);
                        } else {
                            printf("请输入离开时间（年 月 日 时 分）：");
                            scanf("%d %d %d %d %d", &year, &month, &day, &hour, &minute);
                            time_input.tm_year = year - 1900;
                            time_input.tm_mon = month - 1;
                            time_input.tm_mday = day;
                            time_input.tm_hour = hour;
                            time_input.tm_min = minute;
                            time_input.tm_sec = 0;
                            time_input.tm_isdst = -1;
                            current_time = mktime(&time_input);
                        }
                        if (leaveParkingLot(&parkingLot, &waitingQueue, position, current_time)) {
                            printf("车辆离开成功！\n");
                        }
                    }
                }
                printf("\n按回车键返回主菜单...");
                getchar(); getchar();
                break;
                
            case 5:  // 车辆离开便道
                clearScreen();
                printf("=== 车辆离开便道 ===\n");
                if (isWaitingQueueEmpty(&waitingQueue)) {
                    printf("便道为空，没有车辆可以离开！\n");
                } else {
                    printf("请输入要离开便道的车牌号：");
                    scanf("%s", license);
                    if (leaveWaitingQueue(&waitingQueue, license)) {
                        printf("车辆已离开便道！\n");
                    } else {
                        printf("未找到该车牌号的车辆！\n");
                    }
                }
                printf("\n按回车键返回主菜单...");
                getchar(); getchar();
                break;

            case 6:  // 退出程序
                clearScreen();
                printf("=== 显示停车情况 ===\n");
                displayParkingStatus(&parkingLot, &waitingQueue);
                printf("\n感谢使用停车场管理系统，再见！\n");
                break;
                
            default:
                printf("无效选择，请重新输入！\n");
                printf("\n按回车键继续...");
                getchar(); getchar();
                break;
        }
    } while (choice != 6);
    
    // 清理便道内存
    while (!isWaitingQueueEmpty(&waitingQueue)) {
        QueueNode* temp = waitingQueue.front;
        waitingQueue.front = waitingQueue.front->next;
        free(temp);
    }
    
    return 0;
}

// 初始化停车场
void initParkingLot(ParkingLot* lot, int capacity) {
    lot->top = -1;
    lot->capacity = capacity;
}

// 初始化便道队列
void initWaitingQueue(WaitingQueue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->count = 0;
}

// 检查停车场是否已满
int isParkingLotFull(ParkingLot* lot) {
    return lot->top >= lot->capacity - 1;
}

// 检查停车场是否为空
int isParkingLotEmpty(ParkingLot* lot) {
    return lot->top == -1;
}

// 检查便道是否为空
int isWaitingQueueEmpty(WaitingQueue* queue) {
    return queue->front == NULL;
}

// 车辆进入停车场或便道
int parkCar(ParkingLot* lot, WaitingQueue* queue, char* license) {
    // 检查车牌是否已存在
    for (int i = 0; i <= lot->top; i++) {
        if (strcmp(lot->cars[i].license, license) == 0) {
            printf("错误：该车辆已在停车场中！\n");
            return 0;
        }
    }
    
    QueueNode* current = queue->front;
    while (current != NULL) {
        if (strcmp(current->car.license, license) == 0) {
            printf("错误：该车辆已在便道中！\n");
            return 0;
        }
        current = current->next;
    }
    
    if (!isParkingLotFull(lot)) {
        // 停车场有空位，直接停车
        lot->top++;
        strcpy(lot->cars[lot->top].license, license);
        lot->cars[lot->top].position = lot->top + 1;
        printf("车辆已停入停车场，位置：%d\n", lot->top + 1);
        return 1;
    } else {
        // 停车场已满，进入便道
        QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
        if (newNode == NULL) {
            printf("内存分配失败！\n");
            return 0;
        }
        
        strcpy(newNode->car.license, license);
        newNode->car.entry_time = time(NULL);
        newNode->next = NULL;
        
        if (isWaitingQueueEmpty(queue)) {
            queue->front = newNode;
            queue->rear = newNode;
        } else {
            queue->rear->next = newNode;
            queue->rear = newNode;
        }
        
        queue->count++;
        printf("车辆已进入便道等候，前面有%d辆车\n", queue->count - 1);
        return 1;
    }
}

// 车辆离开停车场
int leaveParkingLot(ParkingLot* lot, WaitingQueue* queue, int position, time_t leave_time) {
    if (position < 1 || position > lot->top + 1) {
        printf("位置无效！\n");
        return 0;
    }
    
    int index = position - 1;  // 转换为数组索引
    Car leaving_car = lot->cars[index];
    
    // 计算停车费用
    double fee = calculateFee(leaving_car.entry_time, leave_time);
    int minutes = (int)(fee / PRICE_PER_MINUTE);
    
    // 显示离开信息
    printf("\n=== 车辆离开信息 ===\n");
    printf("车牌号码：%s\n", leaving_car.license);
    printf("停车位置：%d\n", position);
    printf("进入时间：");
    displayTimeInfo(leaving_car.entry_time);
    printf("离开时间：");
    displayTimeInfo(leave_time);
    printf("停车时长：%d分钟\n", minutes);
    printf("停车费用：%.2f元\n", fee);
    
    // 创建临时栈存放需要移出的车辆
    ParkingLot tempStack;
    initParkingLot(&tempStack, lot->capacity);
    
    // 将目标车辆后面的车辆移到临时栈
    for (int i = lot->top; i > index; i--) {
        tempStack.top++;
        tempStack.cars[tempStack.top] = lot->cars[i];
        printf("车辆%s暂时移出停车场让路\n", lot->cars[i].license);
    }
    
    // 目标车辆离开
    lot->top = index - 1;
    
    // 将临时栈中的车辆移回停车场
    while (tempStack.top >= 0) {
        lot->top++;
        lot->cars[lot->top] = tempStack.cars[tempStack.top];
        lot->cars[lot->top].position = lot->top + 1;
        tempStack.top--;
    }
    
    // 如果便道有车辆，将第一辆车移入停车场
    if (!isWaitingQueueEmpty(queue)) {
        QueueNode* first = queue->front;
        lot->top++;
        strcpy(lot->cars[lot->top].license, first->car.license);
        lot->cars[lot->top].entry_time = time(NULL);  // 新进入时间
        lot->cars[lot->top].position = lot->top + 1;
        
        printf("便道车辆%s已进入停车场，位置：%d\n", first->car.license, lot->top + 1);
        
        // 从便道移除
        queue->front = queue->front->next;
        free(first);
        queue->count--;
        
        if (queue->front == NULL) {
            queue->rear = NULL;
        }
    }
    
    return 1;
}

// 车辆离开便道
int leaveWaitingQueue(WaitingQueue* queue, char* license) {
    if (isWaitingQueueEmpty(queue)) {
        return 0;
    }
    
    // 检查队头车辆
    if (strcmp(queue->front->car.license, license) == 0) {
        QueueNode* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
        queue->count--;
        
        if (queue->front == NULL) {
            queue->rear = NULL;
        }
        
        return 1;
    }
    
    // 查找队列中的车辆
    QueueNode* prev = queue->front;
    QueueNode* current = queue->front->next;
    
    while (current != NULL) {
        if (strcmp(current->car.license, license) == 0) {
            prev->next = current->next;
            
            if (current == queue->rear) {
                queue->rear = prev;
            }
            
            free(current);
            queue->count--;
            return 1;
        }
        
        prev = current;
        current = current->next;
    }
    
    return 0;
}

// 显示时间信息
void displayTimeInfo(time_t time_val) {
    struct tm* timeinfo;
    timeinfo = localtime(&time_val);
    printf("%04d-%02d-%02d %02d:%02d:%02d\n",
           timeinfo->tm_year + 1900,
           timeinfo->tm_mon + 1,
           timeinfo->tm_mday,
           timeinfo->tm_hour,
           timeinfo->tm_min,
           timeinfo->tm_sec);
}

// 计算停车费用
double calculateFee(time_t entry_time, time_t leave_time) {
    double seconds = difftime(leave_time, entry_time);
    double minutes = seconds / 60.0;
    
    // 如果停车时间小于1分钟，按1分钟计算
    if (minutes < 1.0 && minutes > 0) {
        minutes = 1.0;
    }
    
    return minutes * PRICE_PER_MINUTE;
}

// 显示停车场和便道状态
void displayParkingStatus(ParkingLot* lot, WaitingQueue* queue) {
    printf("=== 停车场状态 ===\n");
    printf("停车场容量：%d\n", lot->capacity);
    printf("当前停车数量：%d\n", lot->top + 1);
    
    if (lot->top >= 0) {
        printf("\n停车场内车辆：\n");
        printf("%-5s %-15s %-10s %-20s\n", "位置", "车牌号", "进入时间", "已停时间(分钟)");
        printf("-------------------------------------------------\n");
        
        time_t now = time(NULL);
        
        for (int i = 0; i <= lot->top; i++) {
            printf("%-5d %-15s ", i + 1, lot->cars[i].license);
            struct tm* timeinfo = localtime(&lot->cars[i].entry_time);
            printf("%02d:%02d:%02d   ", 
                   timeinfo->tm_hour, 
                   timeinfo->tm_min, 
                   timeinfo->tm_sec);
            
            double minutes = difftime(now, lot->cars[i].entry_time) / 60.0;
            printf("%.1f\n", minutes);
        }
    } else {
        printf("停车场为空\n");
    }
    
    printf("\n=== 便道状态 ===\n");
    printf("便道等候车辆：%d\n", queue->count);
    
    if (!isWaitingQueueEmpty(queue)) {
        printf("\n便道等候车辆：\n");
        printf("%-15s %-10s\n", "车牌号", "进入时间");
        printf("-------------------------\n");
        
        QueueNode* current = queue->front;
        int count = 1;
        
        while (current != NULL) {
            printf("%-15s ", current->car.license);
            struct tm* timeinfo = localtime(&current->car.entry_time);
            printf("%02d:%02d:%02d\n", 
                   timeinfo->tm_hour, 
                   timeinfo->tm_min, 
                   timeinfo->tm_sec);
            
            current = current->next;
            count++;
        }
    } else {
        printf("便道为空\n");
    }
}

// 清屏函数
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}