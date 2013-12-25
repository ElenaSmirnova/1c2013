program erhehgfbfdbfgbn;
const N=100000;
Type    Uk=^W;
W=record;
Inf:integer;
Left:Uk;
Right:Uk;
Ba:Uk;
end;
var T:Uk;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
procedure goi (Hi:Uk);                //çàäàíèå 1
begin
If Hi=nil then
Exit;

write(' ',Hi^.Inf,' ;');
goi(Hi^.Left);
write(' ',Hi^.Inf,' ;');
goi(Hi^.Right);
write(' ',Hi^.Inf,' ;');

end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
procedure adn (var Hi:Uk;const i,pos:integer);                 //çàäàíèå 2
var Ki:Uk;
begin
if pos<0 then
begin
write('Íåêîðåêòíî çàäàíà ïîçèöèÿ');
Exit;
end;
New(Ki);
Ki^.Inf:=i;
if Hi=nil then
begin
write('Èñõîäíîå äåðåâî ïóñòî.Îøèáêà!');
Exit;
end;

If pos= 2 then
begin
Ki^.Left:=nil;
Ki^.Right:=Hi^.Right;
Hi^.Right:=Ki;
Ki^.Ba:=Hi;
Exit;
end;

If pos= 1 then
begin
Ki^.Left:=nil;
Ki^.Right:=Hi^.Right;
Hi^.Right:=Ki;
Ki^.Ba:=Hi;
Exit;
end;

if pos mod 3=0 then
begin
write('Íåêîððåêòíî çàäàííàÿ ïîçèöèÿ');
Exit;
end;

if pos mod 3 =1 then
begin
adn(Hi^.Right,i,round(pos/2));
end
else  adn(Hi^.Left,i,round(pos/2));


end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
procedure ad(var Hi:Uk;const U:Uk;pos:integer);                 //çàäàíèå 3//ïîäðàçóìåâàåòñÿ,÷òî íóæíàÿ ïîçèöèÿ ïóñòà,è íå ÿâëÿåòñÿ êîðíåì äåðåâà(ò.å. íå èä¸ò çàìåíà äåðåâà Hi íà U).Èíà÷å òî,÷òî áûëî íà å¸ ìåñòå,ñòèðàåòñÿ.
begin
if pos<0 then
begin
write('Íåêîððåêòíàÿ çàïèñü ïîçèöèè.Äî ñâèäàíèÿ.');
Exit;
end;


if Hi=nil then
begin
if pos<>0 then
begin
write(' íåâîçìîæíî äîáðàòüñÿ äî íóæíîé ïîçèöèè');
Exit;
end
else
begin Hi:=U;
Exit;
end;
end;


if pos=0 then
begin
write('Îøèáêà ñ çàäàíèåì ïîçèöèè*');
Exit;
end;

if pos=1 then
begin
if Hi^.Left<>nil then write('òàì ÷òî-òî áûëî...íî òû ñò¸ð...æàëü');
Hi^.Left:=U;
U^.Ba:=Hi;
end;

if pos=2 then
begin
if Hi^.Right<>nil then write('òàì ÷òî-òî áûëî...íî òû ñò¸ð...æàëü');
Hi^.Right:=U;
U^.Ba:=Hi;
end;


if pos mod 3=1 then
ad(Hi^.Left,U,round((pos-1)/3));

if pos mod 3=2 then
ad(Hi^.Right,U,round((pos-2)/3));

end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
function mammie(Ui:Uk):Uk;      //çàäàíèå 4//
begin
If Ui=nil then
begin
write(' Ó ïóñòîãî äåðåâà íåò êîðíÿ ');
Exit;
end;

If Ui^.Ba=nil then
begin
result:=Ui;
Exit;
end;

result:=mammie(Ui^.Ba);

end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
function minpar(Hi,Ui:Uk):Uk ;               //çàäàíèå5//
var Ki,Li:Uk;
begin

If (Hi^.Ba=nil) or (Ui^.Ba=nil) then
begin
Ki:=mammie(Ui);
Li:=mammie(Hi);
If Ki=Li then
begin
result:=Ki;
Exit;
end;
end;

If Ui=Hi then
begin
result:=Ui;
Exit;
end;

Ki:=minpar(Hi^.Ba,Ui);
Li:=minpar(Hi,Ui^.Ba);

If  Ki=Li then
begin
result:=Ki;
Exit;
end;

If Ki^.Ba=Li then
result:=Ki;

If Li^.Ba=Ki then
result:=Li;

end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
function fiw(Hi,Ui:Uk):integer;      // ñîïîñòîâëÿåò "ïóòü" èç êîðíÿ â äàííûé ýëåìåíò(1-åcëè íàëåâî,2 - åñëè íàïðàâî,0-åñëè óæå äîáðàëèñü,è òàê â òðîè÷íîé ñèñòåìå),èëè -1,åñëè òàêîãî ýëåìåíòà íåò.
var ki,li:integer;
begin
If Hi=nil then
begin
result:=-1;
Exit;
end;

ki:=fiw(Hi^.Left,Ui);
li:=fiw(Hi^.Right,Ui);

if ki=li then
begin
write('Äåðåâî ó âàñ êàêîå-òî...íå äåðåâî.Òàì ó íåêîåãî óçëà äâà ïðåäêà');
Exit;
end;

If ki>-1 then
begin
result:=3*ki+1;
Exit;
end;

if li>-1 then
begin
result:=3*li+2;
Exit;
end;

result:=-1;

end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
procedure delwo (var Hi:Uk;const Ui:Uk);   //çàäàíèå7//äà óäàëèì ìû ïîääåðåâî
begin
If Hi=nil then
begin
Exit;
end;

If Hi=Ui then
begin
Hi:=nil;
Exit;
end;

delwo(Hi^.Right,Ui);
Delwo(Hi^.Left,Ui);


end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
procedure delel(var Hi:Uk;const Ui:Uk);       //çàäàíèå 8//óäàëåíèå ýëåìåíòà,åñëè îí åñòü(ÎÁßÇÀÒÅËÜÍÀß ÏÐÎÂÅÐÊÀ,×ÒÎ ÈÇ ÍÅÃÎ ÍÅ ÁÎËÅÅ ÄÂÓÕ ÂÅÒÎÊ ÈÄ¨Ò)
begin
if Hi=nil then
begin
Exit;
end;

If (Ui^.Left<>nil)  and (Hi^.Right<>nil) then
begin
write('Ýëåìåíò ñ äâóìÿ âåòêàìè.Äî ñâèäàíèÿ');
Exit;
end;

If Ui^.Left=nil then
begin
If Hi=Ui then
begin
Hi:=Ui^.Right;
Exit;
end;

If Hi^.Left=Ui then
begin
Hi^.Left:=Ui^.Right;

if Ui^.Right<>nil then
Ui^.Right^.Ba:=Hi;
Exit;
end;


If Hi^.Right=Ui then
begin
Hi^.Right:=Ui^.Right;

if Ui^.Right<>nil then
Ui^.Right^.Ba:=Hi;
Exit;
end;

delel(Hi^.Left,Ui);
delel(Hi^.Right,Ui);

Exit;
end
else
begin


{}


If Hi=Ui then
begin
Hi:=Ui^.Left;
Exit;
end;

If Hi^.Left=Ui then
begin
Hi^.Left:=Ui^.Left;

if Ui^.Left<>nil then
Ui^.Left^.Ba:=Hi;
Exit;
end;


If Hi^.Right=Ui then
begin
Hi^.Right:=Ui^.Left;

if Ui^.Left<>nil then
Ui^.Left^.Ba:=Hi;
Exit;
end;

delel(Hi^.Left,Ui);
delel(Hi^.Right,Ui);


Exit;
end;

end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
function wai (Hi:Uk;i:integer):array [1..N] of integer;            //âûäà¸ò âñå ÷èñëàâ òðîè÷íîé ñèñòåìå(ïîñëåäîâàòåëüíîñòè èç 1 è 2,çàïèñàííàÿ â 3-è÷íîé),ãäå ïóòåé íàëåâî íà i áîëüøå,÷åì íàïðàâî.
var Ai,Bi,Ci :array [1..N] of integer;
ji,si:integer;
begin
si:=0;
for ji:=1 to N do
Ai[ji]:=-1;

If Hi=nil then
begin
if i=0 then
Ai[1]:=0;
result:=Ai;
Exit;
end;

If (i=1) and (Hi^.Left=nil) and (Hi^.Right=nil)then
begin
Ai[1]:=1;
end;

Bi:=wai(Hi^.Left,i-1);
Ci:=wai(Hi^.Right,i+1);
si:=1;
While Bi[si]<>-1 do
begin
Ai[si]:=3*Bi[si]+1;
inc(si);
end;

ji:=1;
While Ci[ji]<>-1 do
begin
Ai[si+ji]:=3*Ci[ji]+2;
inc(ji);
end;



result:=Ai;

end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
begin
cls;
New(T);
Dispose(T);
end.