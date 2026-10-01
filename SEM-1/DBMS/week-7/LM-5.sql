declare
	cursor c is select dno,projno,projname,projcredit,proj_fund from proj;
	
	allocamt number(12,2);
	empamt number(12,2);
	deptamt number(12,2);
	empcount number;
begin
	for p in c loop
		allocamt := p.proj_fund * p.projcredit / 10;
		
		select count(*) into empcount from emp where deptno = p.dno and projid = p.projno;

		empamt := allocamt * 0.70 ;

		deptamt := allocamt * 0.30;

		DBMS_OUTPUT.PUT_LINE('Project: ' ||p.projname);
		DBMS_OUTPUT.PUT_LINE('Project fund: ' ||p.proj_fund);
		DBMS_OUTPUT.PUT_LINE('Project credits: ' ||p.projcredit);
		DBMS_OUTPUT.PUT_LINE('Allocated amount: '||allocamt);
		
		if empcount > 0 then
			empamt := empamt / empcount;
			DBMS_OUTPUT.PUT_LINE('Employee count: ' ||empcount);
			DBMS_OUTPUT.PUT_LINE('Incentive for employee: '||empamt);
		else
			DBMS_OUTPUT.PUT_LINE('No of employee working on this project.');
		end if;

		update dept set dept_budget = nvl(dept_budget,0) + deptamt where dno = p.dno;
		DBMS_OUTPUT.PUT_LINE('Added to department budget: ' ||deptamt||chr(10));

	end loop;
	commit;
end;
/




	
		
	