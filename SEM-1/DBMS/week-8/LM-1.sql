declare
	num number;
	empnum emp.empno%type;
	deptno emp.deptno%type;
	name emp.ename%type;
begin
	begin 
		select to_number(ename)into num from emp where empno = 150;
		dbms_output.put_line('Converted number:'||num);
	exception
		when invalid_number then
			dbms_output.put_line('Invalid number name cannot be converted');
		when others then
			dbms_output.put_line('error while converting the name:'||sqlerrm);
	end;
	begin
		empnum := &enter_empno ;
		select ename into name from emp where empno = empnum;
		dbms_output.put_line('Employee name:'||name);
	exception
		when no_data_found then
			dbms_output.put_line('No data found with empno'||empnum);
	end;
	begin
		deptno := '&deptno';
		select ename into name from emp where deptno = deptno;
		dbms_output.put_line('Employee name:'||name);
	exception
		when no_data_found then
			dbms_output.put_line('no data found with that deptno');
		when too_many_rows then
			dbms_output.put_line('too many rows more than 1 employee exists in department');
	end;
end;
/


			
	