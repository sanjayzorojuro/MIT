declare
	projid proj.projno%type := '&projid';
	
	cursor c(c_projid proj.projno%type) is select * from (select e.ename ,e.salary,d.dname as department_name from emp e join dept d on e.deptno = d.dno where e.projid = c_projid order by e.salary desc) where rownum <= 2;

begin
	dbms_output.put_line('Top 2 highest paid employee for project ' || projid);
		
	for rec in c(projid) loop
		dbms_output.put_line(rec.ename||' '||rec.salary||' '||rec.department_name);
	end loop;
end;
/