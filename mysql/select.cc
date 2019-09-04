#include <cstdio>
#include <cstdlib>
#include <mysql/mysql.h>

int main(){
  //1.创建一个MySQL句柄
  MYSQL* mysql = mysql_init(NULL);
  //2.建立连接
   if(mysql_real_connect(mysql,"127.0.0.1","root","","order_system",3306,NULL,0)==NULL){
    printf("mysql 连接失败 %s\n",mysql_error(mysql));
     return 1; 
  }
  //3.设置编码方式
  mysql_set_character_set(mysql,"utf8");
  //4拼装一个SQL语句
  char sql[1024]={0};
  sprintf(sql,"select * from dish_table");
  //5.执行SQL
  int ret = mysql_query(mysql,sql);
  if(ret!=0){
    printf("mysql_query 执行失败 %s\n",mysql_error(mysql));
    mysql_close(mysql);
    return 1;
    }
  //6.获取并遍历结果集合
  MYSQL_RES* result = mysql_store_result(mysql);
  //b)获取结果有几行
  int rows = mysql_num_rows(result);
  int cols = mysql_num_fields(result);
  //c)根据行列遍历结果
  for(int row = 0;row<rows;++row){
    //得到一行数据
    MYSQL_ROW mysql_row = mysql_fetch_row(result);
    //使用[]去下标操作就能获取到每一行
    for(int col = 0;col<cols;++col){
      printf("%s\t",mysql_row[col]);
    }
    printf("\n");
  }
  //7.结果集合需要手动释放
  mysql_free_result(result);
  //8.断开连接
  mysql_close(mysql);
  return 0;
}
