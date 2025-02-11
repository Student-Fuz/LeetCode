#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned char* rxbuf = (unsigned char*) "0x1234567800";  // 字符串 "0x12345678"
    
    // 使用 strtol 函数将字符串转换为 unsigned int，指定基数为 16（十六进制）
    unsigned int result = (unsigned int) strtol((char*)rxbuf, NULL, 16);
    
    printf("Converted value: 0x%X\n", result);  // 输出：Converted value: 0x12345678

    return 0;
}
