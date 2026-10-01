declare
	job emp.job%type := '&job';
	dno emp.deptno%type := '&dno';
	
	cursor c (c_job emp.job%type, c_dno emp.deptno%type) is select empno,ename,job,deptno,salary from emp where job = c_job and deptno = c_dno;

begin
	DBMS_OUTPUT.PUT_LINE('Employees with job = ' || job || ' and department = '|| dno);

	for rec in c(job,dno) loop
		DBMS_OUTPUT.PUT_LINE(rec.empno||' '||rec.ename||' '||rec.job||' '||rec.deptno||' '||rec.salary);
	end loop;
end;
/