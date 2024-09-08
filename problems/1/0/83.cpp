var
	n,a:int64;
begin
	readln(n);
	if n<1 then begin
		writeln(-1);
	end;
	if n>=1 then begin
		a:=n*(n+1)/2;
		writeln(a);
	end;
end.