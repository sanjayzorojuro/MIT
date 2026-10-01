declare
	eno emp.empno%type := &eno;
	name emp.ename%type;
	deptname dept.dname%type;
	sal emp.salary%type;
begin
	select e.ename ,d.dname,e.salary into name,deptname,sal from emp e join dept d on e.deptno = d.dno where e.empno = eno;
	dbms_output.put_line(name||' works in '||deptname||' department and draws '||sal||' as salary.');
exception 
	WHEN NO_DATA_FOUND THEN 
		dbms_output.put_line('Employee not found');
end;
/
	