#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

int main()
{
    //创建一个空的文档(对象)
    cJSON *json = cJSON_CreateObject();

    //向文档增加一个键值对{"name":"王大锤"}
    //cJSON_AddItemToObject(json, "name", cJSON_CreateString("王大锤"));
    cJSON_AddStringToObject(json, "name", "王大锤");

    //向文档添加一个键值对
    //cJSON_AddItemToObject(json, "age", cJSON_CreateNumber(29));
    cJSON_AddNumberToObject(json, "age", 29);


    cJSON *array = NULL;
    cJSON_AddItemToObject(json, "love", array=cJSON_CreateArray());
    cJSON_AddItemToArray(array, cJSON_CreateString("LOL"));
    cJSON_AddItemToArray(array, cJSON_CreateString("NBA"));
    cJSON_AddItemToArray(array, cJSON_CreateString("Go shopping"));

    cJSON_AddNumberToObject(json, "score", 59);
    cJSON_AddStringToObject(json, "address", "beijing");

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
