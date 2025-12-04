// decimal_to_octal.c
#include <stdio.h>
#include <stdint.h>

void to_octal(int64_t n, char *out) {
    // 处理零的特殊情况
    if (n == 0) {
        out[0] = '0';
        out[1] = '\0';
        return;
    }

    int is_negative = n < 0;
    uint64_t x = is_negative ? -(uint64_t)n : (uint64_t)n; // 用无符号处理绝对值

    char buf[70]; // 足够存储 64 位数的八进制表示
    int idx = 0;

    // 手动进制转换：除以 8 取余
    while (x > 0) {
        int digit = x % 8;
        buf[idx++] = '0' + digit;
        x /= 8;
    }

    int out_idx = 0;
    if (is_negative) {
        out[out_idx++] = '-';
    }

    // 反转写入
    for (int i = idx - 1; i >= 0; --i) {
        out[out_idx++] = buf[i];
    }
    out[out_idx] = '\0';
}

int main() {
    long long n;
    printf("请输入一个十进制整数: ");
    if (scanf("%lld", &n) != 1) {
        fprintf(stderr, "输入错误。\n");
        return 1;
    }

    char oct[80];
    to_octal((int64_t)n, oct);
    printf("八进制表示: %s\n", oct);
    return 0;
}