declare
	cursor c is select d.dname,e.empno,e.ename,e.job,e.salary from dept d join emp e on d.dno = e.deptno order by d.dno,e.empno;

	currentdept dept.dname%type := null;
begin
	for rec in c loop
		if currentdept is null or currentdept <> rec.dname then 
			DBMS_OUTPUT.PUT_LINE(chr(10) || 'Department: ' || rec.dname);
			currentdept := rec.dname;
		end if;
		DBMS_OUTPUT.PUT_LINE('   '|| rec.empno ||'  ' || rec.ename ||'  ' || rec.job ||'  ' || rec.salary);
	END LOOP;
end;
/
					
	

	