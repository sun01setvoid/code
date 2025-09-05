继承基类的private(存在)，但不可见，你不可使用
public 继承不改变权限
protected （public->降权限）
private (都降成private)

//传递后，同名成员函数会覆盖
//除非你使用域解析符去访问上层的函数

//类似于把上层的全部构造一遍，再加上自己的