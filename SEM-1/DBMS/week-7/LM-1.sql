set serveroutput on
declare
	cursor d is select dno from dept where rownum <= 5;
	dno emp.deptno%type;

begin
	dbms_output.put_line('First five department number:');
	for rec in d loop
		dbms_output.put_line(rec.dno);
	end loop;
end;
/



