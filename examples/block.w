int a = 1
int b = 2
int c = 3
{
    int a = 10
    b = 20
    {
        int a = 100
        int b = 200
        print(a + b + c)
    }
    print(a)
    print(b)
}
print(a)
print(b)
print(c)
{
    int c = 300
    print(c)
}
print(c)