program idjdhjfh;
const N=10; //����� � ��������� ����������/�������� ������ maxInt,������� ������-�� �� ������,� ��������� ����������� ������,������� ������������ ���������� ��� �������.
Type uk=^S;
S=record
Inf:integer;
Uka:uk;
end;

var j,i,k1,k2,k22:integer;
u,w,T:uk;
A:array [-N..N] of integer;
B,C:array [1..N] of uk;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
function num (const Hi:uk;m:integer):integer;          //1 �������
var i:integer;
Ti:uk;
begin
Ti:=nil;
If m<=0 then
begin
write('���������������� �����* ');
result:=-2;
Exit;
end;
Ti:=Hi;

For i:=1 to m-1 do
begin
If (Ti^.Uka=nil) or (Ti=nil) then
begin
write('���������������� �����**5 ');
result:=-1;
Exit;
end;
Ti:=Ti^.Uka;
end;

result:=Ti^.Inf;
end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
function len(Hi:uk):integer;      //������� 2
begin
If Hi=nil then result:=0
else result:=1+len(Hi^.Uka);
end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
function rev(const Hi:uk):uk;                 // ������� 3
var Ti:uk;
Aj:array [0..N] of uk;
ji,ki:integer;

begin
If Hi=nil then Exit;
Ti:=Hi;
ji:=1;
While Ti<>nil do
begin
Aj[ji]:=Ti;
Ti:=Ti^.Uka;
inc(ji);
end;
Aj[0]:=nil;
For ki:=1 to ji-1 do
begin
Aj[ji-ki]^.Uka:=Aj[ji-ki-1];
end;
result:=Aj[ji-1];
end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
function cir (Hi:uk):boolean;          //������� 4       //������,���� �� ����?
var Ai:array [1..N] of uk;
Ti:uk;
ji,ki:integer;
begin
Ti:=Hi;
ji:=1;
while Ti<>nil do
begin
Ai[ji]:=Ti;
Ti:=Ti^.Uka;

For ki:=1 to ji do
begin
if Ti=Ai[ki] then
begin
result:=true;
Exit;
end;
end;

inc(ji);
end;
result:=false;
end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
function  minp(const Hi:uk):integer ;     //������� 5        //�������������� �������� �� ������������� � ���������� � ����� �������(���� ��� � ������� �������).����������� ����������� �� �������,�����������.
var Ti:uk;
ji,Li,ki,mi:integer;
Ai:array [1..N] of uk;
begin
for ji:=1 to N do
Ai[ji]:=nil;

Li:=1;
ji:=Hi^.Inf;;
Ti:=Hi;
mi:=1;
while Ti<>nil do
begin
For ki:=1 to mi-1 do
begin
if Ti=Ai[ki] then
begin
result:=Li;
Exit;
end;
end;

If ji> Ti^.Inf then
begin
Li:=mi;
ji:=Ti^.Inf;
end;

Ai[mi]:=Ti;
Ti:=Ti^.Uka;
inc(mi);
end;

result:=Li;
end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
function cou (const Hi:uk):array [-N..N] of integer;    //������ 6 //������������ ������,��� result[i] - ���������� ����� � ������,������ i.
var ji,mi,ki,epsilon:integer;
Ti:uk;
Ai:array [-N..N] of integer;
Bi:array [1..N] of uk;

begin
For ji:=-N to N do
Ai[ji]:=0;
For ji:=1 to N do
Bi[ji]:=nil;
Ti:=Hi;
mi:=1;
While Ti<>nil do
begin
epsilon:=0;

For ki:=1 to mi-1 do
begin
if Ti=Bi[ki] then
begin
epsilon:=1;
Break;
end;
end;

if epsilon=1 then Break;

inc(Ai[Ti^.Inf]);
Bi[mi]:=Ti;
Ti:=Ti^.Uka;
inc(mi);
end;
result:=Ai;
end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
begin
cls;              //������� � ��� ������ ��������� �������� �������� ������ �� �������������(��� ������� ������� �� ������),�� � ����� �������� ������� ���������� ��������� �� ����� ������ �� �����
New(u);
New(w);
New(T);
u^.Inf:=6;
u^.Uka:=w;
w^.Inf:=4;
w^.Uka:=nil;


write('������� ���������� ��������� � ������: ');
Read(i);
k1:=i;
New(B[1]);
for j:=1 to i do
begin
New(B[j+1]);
write('��������-�� ����� � �������� � ������� ',j,' : ');
read(B[j]^.Inf);
if  j=i then
B[j]^.Uka:=nil
else B[j]^.Uka:=B[j+1];

end;
write('� ������ ��� ������������:������� ���������... ');
read(k2);
write(' ...� � ����� �������������. ');
read(k22);

New(C[1]);
for j:=1 to k2 do
begin
New(C[j+1]);
write('��������-�� ����� � �������� � ������� ',j,' : ');
read(C[j]^.Inf);
if  j=k2 then
C[j]^.Uka:=C[k22]
else C[j]^.Uka:=C[j+1];

end;

write('������� �������,��������� : ');
read(i);
if  i<1 then
writeln('1)�� ��� ������...')
else
begin
writeln('1)��� ������� ',i,' � ��� ���...(���������� �����) ',num(B[1],i)  );
end;

writeln('2)������ ������ ������(������� �� � ��� ������): ',len(B[1]));


{T:=rev(B[1]);                       //�� ����������� ��� ������� ���� �������� ���� ����� ���� � �������� ��������� - ��� �������� ��������,������ �������� ���� ����� ����,������� ��� �������  3 ������� ����������� ������ B[1];
write('3)����������� ������:');
for j:=1 to k1 do
begin
write(T^.Inf,' ;');
T:=T^.Uka;
end;
writeln;}

writeln('5)*(����������� ������� ������������ ��������)(��� B)', minp(B[1]));
writeln('5)**(����������� ������� ������������ ��������)(��� C)', minp(C[1]));

write('6)*');
A:=cou(B[1]);
for j:=-N to N do
If A[j]<>0 then
begin
write('(',j,',',A[j],' ���)');
end;

writeln;
write('6)**');

A:=cou(C[1]);
for j:=-N to N do
If A[j]<>0 then
begin
write('(',j,',',A[j],' ���)');
end;




for j:=1 to k1+1 do
Dispose(B[j]);
for j:=1 to k2+1 do
Dispose(C[j]);
end.