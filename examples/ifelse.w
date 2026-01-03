int x = 50
int y = 100
int status = 0

if (x < y) {
    int x = 10
    if (x > 5) {
        status = 1
    } else {
        status = 2
    }
    print(status)
    print(x)
} else {
    status = 3
    print(status)
}

print(status)
print(x)

{
    int y = 200
    if (y == 200) {
        x = x + 10
        int x = 999
        print(x)
    } else {
        print(0)
    }
    print(y)
    print(x)
}

print(x)
print(y)