#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int id;
    int time;
} Record;
int timeToSeconds(char *timeStr) {
    int h, m, s;
    sscanf(timeStr, "%d:%d:%d", &h, &m, &s);//从字符串中读
    return h * 3600 + m * 60 + s;
}
void secondsToTime(int seconds, char *result) {
    int h = seconds / 3600;
    int m = (seconds % 3600) / 60;
    int s = seconds % 60;
    sprintf(result, "%02d:%02d:%02d", h, m, s);//写入字符串
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int timeSpent[1010]={0};
    for (int i = 0; i < m; i++) {
        char id[4], startTime[9], endTime[9];
        scanf("%s %s %s", id, startTime, endTime);
        int idNum=atoi(id);
        int startSec = timeToSeconds(startTime);
        int endSec = timeToSeconds(endTime);
        timeSpent[idNum] += (endSec - startSec);
    }
    Record records[1010];
    for (int i = 0; i < n; i++) {
        records[i].id = i;
        records[i].time = timeSpent[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (records[j].time < records[j + 1].time ||(records[j].time == records[j + 1].time && records[j].id > records[j + 1].id)){
                Record temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        char timeStr[9];
        secondsToTime(records[i].time, timeStr);
        printf("%03d %s\n", records[i].id, timeStr);
    }
    return 0;
}
