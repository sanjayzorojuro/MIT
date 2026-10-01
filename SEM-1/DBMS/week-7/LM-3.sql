declare
	eno emp.empno%type := &eno;
	ename emp.ename%type;
	sal emp.salary%type;
	hra   number(10,2);
	da    number(10,2);
	gross number(10,2);
	pf    number(10,2);
	net   number(10,2);
begin
	select ename, salary into ename,sal from emp where empno = eno;
	
	hra := sal*0.50;
	da := sal*0.20;
	gross := sal+hra+da;
	pf := sal*0.12;
	net := gross - pf;

	insert into empsal values(eno,ename,sal,hra,da,gross,pf,net);
	
	DBMS_OUTPUT.PUT_LINE('Employee name:' ||ename);
	DBMS_OUTPUT.PUT_LINE('Salary:' ||sal);
	DBMS_OUTPUT.PUT_LINE('HRA:' ||hra);
	DBMS_OUTPUT.PUT_LINE('DA:' ||da);
	DBMS_OUTPUT.PUT_LINE('Gross Salary:' ||gross);
	DBMS_OUTPUT.PUT_LINE('PF:' ||pf);
	DBMS_OUTPUT.PUT_LINE('Net Salary:' ||net);

exception 
	When no_data_found then
		DBMS_OUTPUT.PUT_LINE('Employee not found');
end;
/