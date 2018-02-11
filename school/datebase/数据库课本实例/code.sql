//3.5
create table Student(
Sno char(9) primary key,
Sname char(20) unique,
Ssex char(2),
Sage smallint,
Sdept char(20)
);

//3.6
create table Course(
Cno char(4) primary key,
Cname char(40) not null,
Cpno char(4),
Ccredit smallint,
foreign key (Cpno) references Course(Cno)
);

//3.7
create table SC(
Sno char(9),
Cno char(4),
Grade smallint,
primary key(Sno,Cno),
foreign key (Sno) references Student(Sno),
foreign key (Cno) references Course(Cno)
);

//3.8
alter table Student 
add S_entrance date;

//3.9
alter table Student 
alter column Sage int;

//3.10
alter table Coursea
add unique(Cname);

//3.11
drop table Student cascade;

//3.12
create view is_Student
as
select Sno,Sname,Sage
from Student
where Sdept='IS';

drop table Student restrict;

drop table Student cascade;

select *
from IS_Student;

//3.13
create unique index Stusno on Student(Sno);
create unique index Coucno on Course(Cno);
create unique index SCon on SC(Sno asc, Cno desc);

//3.14
alter index SCno rename  to SCSno;

//3.15
drop index Stusname;

//3.16
select Sno,Sname
from Student;

//3.17
select Sname, Sno, Sdept
from Student;

//3.18
select *
from Student;

//3.19
select Sname,2014-Sage
from Student;

//3.20
select Sname,'Year of Brith:',2014-Sage,LOWER(Sdept)
from Student;

select Sname NAME,'Year of Brith:' BIRTH,2014-Sage BIRTHDAY,LOWER(Sdept) DEPARTMENT
from Student;

//3.21
select Sno
from SC;

select DISTINCT Sno
from SC;

//3.22
select Sname
from Student
where Sdept='CS';

//3.23
select Sname, Sage
from Student
where Sage<20;

//3.24
select distinct Sno
from SC
where Grade<60;

//3.25
select Sname,Sdept,Sage
from Student
where Sage between 20 and 23;

//3.26
select Sname,Sdept,Sage
from Student
where Sage not between 20 and 23;

//3.27
select Sname,Ssex
from Student
where Sdept in('CS','MA','IS');

//3.28
select Sname,Ssex
from Student
where Sdept not in('CS','MA','IS');

//3.29
select *
from Student
where Sno like '201215121';

//3.30
select Sname,Sno,Ssex
from Student
where Sname like '刘%';

//3.31
select Sname
from Student
where Sname like '欧阳_';

//3.32
select Sname,Sno
from Student
where Sname like '_阳%';

//3.33
select Sname,Sno,Ssex
from Student
where Sname not like '刘%';

//3.34 少一句
select Cno,Ccredit
from Course


//3.35  少一句
select *
from Course


//3.36
select Sno,Cno
from SC
where Grade is null;

//3.37
select Sno,Cno
from SC
where Grade is not null;

//3.38
select Sname
from Student
where Sdept='CS' and Sage<20;

//3.39
select Sno,Grade
from SC
where Cno='3'
order by Grade DESC;

//3.40
select *
from Student
order by Sdept,Sage DESC;

//3.41
select count(*)
from Student;

//3.42
select count(distinct Sno)
from SC;

//3.43
select avg(Grade)
from SC
where Cno='1';

//3.44
select max(Grade)
from SC
where Cno='1';

//3.45
select sum(Ccredit)
from SC,Course
where Sno='201215012' and SC.Cno=Course.Cno;

//3.46
select Cno,count(Sno)
from SC
group by Cno;

//3.47
select Sno
from SC
group by Sno
having count(*)>3;

//3.48
select Sno,avg(Grade)
from SC
group by Sno
having avg(Grade)>=90;

//3.49
select Student.*,SC.*
from Student,SC
where Student.Sno=SC.Sno; 

//3.50
select Student.Sno,Sname,Ssex,Sdept,Cno,Grade
from Student,SC
where Student.Sno=SC.Sno;

//3.51
select Student.Sno,Sname
from Student,SC
where Student.Sno=SC.Sno and SC.Cno='2' and SC.Grade>90;

//3.52
select FIRST.Cno,SECOND.Cpno
from Course FIRST, Course SECOND
where FIRST.Cpno=SECOND.Cno;
//3.53
select Student.Sno,Sname,Ssex,Sage,Sdept,Cno,Grade
from Student left outer join SC on(Student.Sno=SC.Sno);

//3.54
select Student.Sno,Sname,Cname,Grade
from Student,SC,Course
where Student.Sno=SC.Sno and SC.Cno=Course.Cno;

//3.55
select Sno,Sname,Sdept
from Student
where Sdept in(
				select Sdept
				from Student
				where Sname='刘晨');

//3.56
select Sno,Sname
from Student
where Sno in(
				select Sno
				from SC
				where Cno in(
								select Cno
								from Course
								where Cname='信息系统'
							)
			);

//3.57
select Sno,Cno
from SC x
where Grade>=(
				select avg(Grade)
				from SC y
				where y.Sno=x.Sno
			);

//3.58
select Sname,Sage
from Student
where Sage<any(
				select Sage
				from Student
				where Sdept='CS'
			)
and Sdept<>'CS';

//3.59
select Sname, Sage
from Student
where Sage<all(
				select Sage
				from Student
				where Sdept='CS'
			)
and Sdept<>'CS'

//3.60
select Sname
from Student
where exists(
				select *
				from SC
				where Sno=Student.Sno and Cno='1'
			)

//3.61
select Sname
from Student
where not exists(
				select *
				from SC
				where Sno=Student.Sno and Cno='1'
			)

//3.62
select Sname
from Student
where not exists(
					select *
					from Course
					where not exists(
										select *
										from SC
										where Sno=Student.Sno and Cno=Course.Cno
									)
				);

//3.63
select distinct Sno
from SC SCX
where not exists(
					select *
					from SC SCY
					where SCY.Sno='201215122' and not exists(
																select *
																from SC SCZ
																where SCZ.Sno=SCX.Sno and SCZ.Cno=SCY.Cno
															)
				);
				
//3.64
select *
from Student 
where Sdept='CS'

union

select *
from Student
where Sage<=19;

//3.65
select Sno
from SC
where Cno='1'

union

select Sno
from SC
where Cno='2';

//3.66
select *
from Student 
where Sdept='CS'

intersect

select *
from Student
where Sage<=19;

//3.67
select Sno
from SC
where Cno='1'

intersect

select Sno
from SC
where Cno='2';

//3.68
select *
from Student 
where Sdept='CS'

except

select *
from Student
where Sage<=19;

//3.69
insert
into Student(Sno,Sname,Ssex,Sdept,Sage)
values('201215128','陈冬','男','IS',18);

//3.70
insert 
into Student
values('201215126','张成民','男',18,'CS');

//3.71
insert
into SC(Sno,Cno)
values('201215128','1');


insert 
into SC
values('201215128','1',null);

//3.72
create table Dept_age
					(Sdept char(15),
					Avg_age smallint);

insert 
into Dept_age(Sdept,Avg_age)
select Sdept,AVG(Sage)
from Student
group by Sdept;

//3.73
update Student
set Sage=22
where Sno='201215121';

//3.74
update Student
set Sage=Sage+1;

//3.75
update SC
set Grade=0
where Sno in(
				select Sno
				from Student
				where Sdept='CS'
			);
			
//3.76
delete 
from Student
where Sno='201215128';

//3.77
delete
from SC;

//3.78
delete 
from SC
where Sno in(
				select Sno
				from Student
				where Sdept='CS'
			);

//3.79
insert 
into SC(Sno,Cno,Grade)
values('201215126','1',null);

//3.80
update Student
set Sdept=null
where Sno='201215200';

//3.81
select *
from Student
where Sname is null or Ssex is null or Sage is null or Sdept is null;

//3.82
select Sno
from SC
where Grade<60 and Cno='1';

//3.83
select Sno
from SC
where Grade<60 and Cno='1'

union

select Sno
from SC
where Grade is null and Cno='1';

//3.84
create view IS_Student
as
select Sno,Sname,Sage
from Student
where Sdept='IS';

//3.85
create view IS_Student
as
select Sno,Sname,Sage
from Student
where Sdept='IS'
with check option;

//3.86
create view IS_S1(Sno,Sname,Grade)
as
select Student.Sno,Sname,Grade
from Student,SC
where Sdept='IS' and Student.Sno=SC.Sno and SC.Cno='1';

//3.87
create view IS_S2
as
select Sno,Sname,Grade
from IS_S1
where Grade>=90;

//3.88
create view BT_S(Sno,Sname,Sbirth)
as
select Sno,AVG(Grade)
from SC
group by Sno

//3.89
create view S_G(Sno,Gavg)
as
select Sno,AVG(Grade)
from SC
group by Sno;

//3.90
create view F_Student(F_sno,name,sex,age,dept)
as
select *
from Student
where Ssex='女';

//3.91
drop view BT_S;
drop view IS_S1;

drop view IS_S1 cascade;

//3.92
select Sno,Sage
from IS_Student
where Sage<20;

//3.93
select IS_Student.Sno,Sname
from IS_Student,SC
where IS_Student.Sno=SC.Sno and SC.Cno='1';

//3.94
select *
from S_G
where Gavg>=90;

select Sno,AVG(Grade)
from SC
group by Sno
having avg(Grade)>=90;

//3.95
update IS_Student
set Sname='刘辰'
where Sno='201215122';

//3.96
insert
into IS_Student
values('201215129','赵新',20);

//3.97
delete
from IS_Student
where Sno='201215129';
























