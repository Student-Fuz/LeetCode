#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    unsigned char* rxbuf = (unsigned char*) "0x1234567800";  // 字符串 "0x1234567800"
    
    // 创建一个临时数组用于存储前 8 个字符
    char temp[11];  // 包含 '\0' 需要多分配 1 个字节
    strncpy(temp, (char*)rxbuf, 10);  // 复制前 10 个字符 ("0x12345678")
    temp[10] = '\0';  // 确保字符串以 '\0' 结尾

    // 使用 strtol 函数将前 8 位字符串转换为 unsigned int
    unsigned int result = (unsigned int) strtol(temp, NULL, 16);

    printf("Converted value: 0x%X\n", result);  // 输出：Converted value: 0x12345678

    return 0;
}
