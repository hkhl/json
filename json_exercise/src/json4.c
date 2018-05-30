#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

int main()
{
    //创建一个空的文档(对象)
    cJSON *json = cJSON_CreateObject();

    //向文档增加一个键值对
    cJSON_AddStringToObject(json, "country", "china");

    //添加数组
    cJSON *array = NULL;
    cJSON_AddItemToObject(json, "stars", array=cJSON_CreateArray());
    //在数组上添加对象
    cJSON *obj = NULL;
    cJSON_AddItemToArray(array, obj=cJSON_CreateObject());
    cJSON_AddItemToObject(obj, "name", cJSON_CreateString("Fays"));
    cJSON_AddStringToObject(obj, "address", "beijing");

    //在对象上添加键值对
    cJSON_AddItemToArray(array, obj=cJSON_CreateObject());
    cJSON_AddItemToObject(obj, "name", cJSON_CreateString("andy"));
    cJSON_AddItemToObject(obj, "address", cJSON_CreateString("HK"));

    cJSON_AddItemToArray(array, obj=cJSON_CreateObject());
    cJSON_AddStringToObject(obj, "name", "eddie");
    cJSON_AddStringToObject(obj, "address", "TaiWan");

    //将传入的JSON结构转化为字符串 并打印
    char *buf = NULL;
    printf("data:%s\n", buf = cJSON_Print(json));
    //打开一个exec.hson文件, 并写入json内容
    FILE *fp = fopen("exec.json", "w");
    fwrite(buf, strlen(buf), 1, fp);

    //清理工作
    fclose(fp);
    free(buf);
    cJSON_Delete(json);
    return 0;
}
