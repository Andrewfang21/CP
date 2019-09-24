var
	n,i,modus,maks,x : longint;
	a,nilai : array[1..100001] of longint;
begin
	readln(n);
	maks := 0;
	modus := 0;
	x := 0;
	for i := 1 to n do
	begin
		read(a[i]);
		inc(nilai[a[i]]);
		if (x <= a[i]) then
		begin
			x := a[i];
		end;
		if (maks <= nilai[a[i]]) then
		begin
			maks := nilai[a[i]];
		end;
	end;
	for i := 1 to x do
	begin
		if (maks <= nilai[i]) then
		begin
			if (modus <= i) then
			begin
				modus := i;
			end;
		end;
	end;
	writeln(modus);
end.
