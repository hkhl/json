#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

int main()
{
    char *char_json = "{\"habit\":\"lol\"}";
    //从缓冲区解析出json结构
    cJSON *json = cJSON_Parse(char_json);
    //将传入的JSON结构转化为字符串 并打印

    char *buf = NULL;
    printf("data:%s\n", buf = cJSON_Print(json));
    //打开一个exec.hson文件, 并写入json内容
    FILE *fp = fopen("exec.json", "w");
    fwrite(buf, strlen(buf), 1, fp);

    fclose(fp);
    free(buf);
    cJSON_Delete(json);
    return 0;
}
