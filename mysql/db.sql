create database if not exists order_system charset=utf8;
use order_system;

create table if not exists dish_table(
  dish_id int not null primary key auto_increment,
  name varchar(50),
  price int
);

insert into dish_table values(null,'火腿鸡蛋',1200);
insert into dish_table values(null,'青椒肉丝',1600);
insert into dish_table values(null,'孜然排骨',1800);
insert into dish_table values(null,'红烧鱼块',2000);

create table if not exists order_table(
  order_id int not null primary key auto_increment,
  table_id varchar(50),
  time varchar(50),
  dishes varchar(1024),
  status int
);

insert into order_table values(null,'凌霄阁','2019/07/01','1,2,3',0);
insert into order_table values(null,'紫云阁','2019/07/01','1',0);
insert into order_table values(null,'清音阁','2019/07/01','1,2',0); 


