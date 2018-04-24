int myAtoi(char* str)
{
    // 空字符串
    if (*str == '\0')
        return 0;
    int result = 0, sign = 1, len = strlen(str), i = 0;
    // 剔除空格符
    while (i < len && str[i] == ' ')
        i++;
    // 判断数的符号
    if (str[i] == '+' || str[i] == '-') {
        sign = str[i++] == '+' ? 1 : -1;
    }
    // 数字的char参与计算
    while (i < len && str[i] >= '0' && str[i] <= '9') {
        // 判断溢出
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && str[i] - '0' > 7))
            return (sign == 1) ? INT_MAX : INT_MIN;
        // 计算数值
        result = result * 10 + (str[i++] - '0');
    }
    return result * sign;
}
