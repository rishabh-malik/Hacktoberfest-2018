(* JOGO: campo minado
 *  O jogador seleciona uma posicao do tabuleiro.
 *  Se esta posicao contiver uma bomba, o jogo termina.
 *  Caso contrario, esta posicao e todas as vizinhas que contiverem 0 bombas
 *  vizinhas sao abertas.
 *)
program campoMinado;

USES CRT;

CONST
   MAX	    = 20;   (* dimensao da matriz quadrada *)
   MAXPILHA = MAX*MAX;
   ERRO	    = 0;
   OK	    = 1;

   VBOMBA =  -1; (* valor na matriz que marca a existencia de bomba *)

   ESPERA    = 100;
   
   CIMA	     = #72; (* ^ *)
   ESQ	     = #75; (* < *)
   DIR	     = #77; (* > *)
   BAIXO     = #80; (* v *)
   ENTER     = #13; (* ENTER *)  
   MARCA     = 'm';
   FIM	     = #27; (* ESC *)
   ZERO	     = #0;

   POS_ATUAL = ' @';
   FECHADO   = ' _';
   MARCADO   = ' m';

TYPE
   TpCelula = record
		 nBombas : integer;
		 aberto	 : boolean;
		 marcado : boolean;
	      end;	 
   TpMatriz = array [0..MAX+1,0..MAX+1] of TpCelula; (* tabuleiro *)
   TpJogo   = record
		 nLin, nCol : integer;
		 nBombas    : integer;
		 m	    : TpMatriz;
	      end;	    
   
   TpPosicao = record
		  lin, col : integer;
	       end;	   
   TpItem    = TpPosicao;
   TpPilha   = record
		  item : array[1..MAX*MAX] of TpItem;
		  topo : integer;
	       end;    

var
   j			    : TpJogo;
   pos			    : TpPosicao;
   ch			    : char;
   sair, perdeu		    : boolean;
   nCelAberto, celParaAbrir : integer;

   cor			    :array [-1..8] of integer =
   (Red, White, Yellow, Green, Cyan, Magenta, Brown, LightGray,
    LightGreen, LightRed);

   letra                    :array[-1..8] of string[2] =
   (' *', '  ', ' 1', ' 2', ' 3', ' 4', ' 5', ' 6', ' 7', ' 8');

(*-----------------------------------------------------------------------
 * TAD Pilha
 *)
procedure criaPilha( var p: TpPilha );
begin
  p.topo:= 0;
end;

function pilhaVazia( p: TpPilha ): boolean;
begin
  pilhaVazia:= p.topo = 0;
end;

function empilha( var p: TpPilha; item: TpItem ): integer;
begin
  if p.topo = MAXPILHA then
    empilha:= ERRO
  else begin
     p.topo:= p.topo + 1;
     p.item[p.topo]:= item;
     empilha:= OK;
  end;
end;

function desempilha(var p : TpPilha; var item: TpItem ): integer;
begin
   if p.topo = 0 then
      desempilha:= ERRO
   else begin
      item:= p.item[p.topo];
      p.topo:= p.topo - 1;
      desempilha:= OK;
   end;
end; { desempilha }

(*-----------------------------------------------------------------------
Leitura de movimento do teclado
 *)
function leEntrada():char;
var
   ch : char;
begin
   if keypressed then begin
      ch:= readkey;
      if ch = #0 then
	 ch:= readkey;
      leEntrada:= ch;
   end
   else
      leEntrada:= ZERO;
end; { leEntrada }



(*-----------------------------------------------------------------------
 * Procedimentos para inicializacao do jogo
 *)
procedure zeraTabuleiro(var j: TpJogo );
var
   l, c	: integer;
begin
   for l:= 0 to j.nLin+1 do
      for c:= 0 to j.nCol+1 do
      begin
	 j.m[l,c].nBombas:= 0;
	 j.m[l,c].aberto:= false;
	 j.m[l,c].marcado:= false;
      end;
end; { zeraTabuleiro }


procedure criaBombas (var j: TpJogo );
var
   l, c, i : integer;
begin
   randomize();
   i:= 0;
   while i < j.nBombas do
   begin
      l:= random(j.nLin) + 1;
      c:= random(j.nCol) + 1;
      if j.m[l,c].nBombas = 0 then
      begin
	 j.m[l,c].nBombas:= VBOMBA;
	 i:= i+1;
      end;
   end;
end; { criaBombas }

procedure contaVizinhos(var j: TpJogo );

var
   l, c, i, k, cont: integer;
begin
   for l:= 1 to j.nLin do
      for c:= 1 to j.nCol do
	 if j.m[l,c].nBombas <> VBOMBA then
	 begin
	    cont:= 0;
	    for i:=l-1 to l+1 do
	       for k:= c-1 to c+1 do
		  if j.m[i,k].nBombas = VBOMBA then
		     cont:= cont+1;
	    j.m[l,c].nBombas:= cont;
	 end;
end; { contaVizinhos }


procedure criaJogo(var j: TpJogo; var posIni: TpPosicao);
begin
   writeln;
   writeln('Operacoes do jogo:');
   writeln;
   writeln('<enter>: seleciona');
   writeln('m      : marca/desmarca posicao');
   writeln('<esc>  : finaliza o jogo');
   writeln;
   
   writeln('Entre com numero de linhas, colunas e bombas (max= ', MAX, '):');
   readln (j.nLin, j.nCol, j.nBombas);
   zeraTabuleiro( j );
   criaBombas( j );
   contaVizinhos( j );
   posIni.lin:= 1;
   posIni.col:= 1;
end; { criaJogo }

(*-----------------------------------------------------------------------
 Imprime a matriz de cores, usa a biblioteca CRT para limpar a tela e para 
 imprimir o conteudo da matriz de forma colorida.
*)

procedure mostraJogo(j: TpJogo; pos: TpPosicao);
var
   l, c	: integer;
begin
   clrscr; 
   for l:= 0 to (j.nCol+1)*2 do
      write('#');
   writeln;
   
   for l:= 1 to j.nLin do
   begin
      write('#');

      for c:= 1 to j.nCol do
      begin
	 textcolor( white );
	 if (l = pos.lin) and (c = pos.col) then
	    write( POS_ATUAL )
	 else if not j.m[l,c].aberto then
	    write( FECHADO )
	 else if j.m[l,c].marcado then
	 begin
	    textcolor( red );
	    write( MARCADO );
	 end
	 else begin
	    textcolor( cor[j.m[l,c].nBombas] );
	    write( letra[j.m[l,c].nBombas] );
	 end;
      end;

      textcolor( White );
      writeln(' #');
   end;

   for l:= 0 to (j.nCol+1)*2 do
      write('#');
   writeln;
end; { mostraJogo }

(*-----------------------------------------------------------------------
 Procedimentos para tratar operacoes do jogo
 *)
function posFechada(j : TpJogo; pos: TpPosicao):boolean;
begin
   posFechada:=  not j.m[pos.lin, pos.col].aberto;
end;
		     
procedure abreTudo (var j : TpJogo );
var
   l, c	: integer;
begin
   for l:= 1 to j.nLin do
      for c:= 1 to j.nCol do
	 j.m[l,c].aberto:= true;
end;


procedure movePosicao (	direcao : char;  j : TpJogo; var pos: TpPosicao );
var
   novaLin, novaCol : integer;
begin
   novaLin:= pos.lin; novaCol:= pos.col;
   case direcao of
     CIMA  : novaLin:= pos.lin - 1;
     BAIXO : novaLin:= pos.lin + 1;
     ESQ   : novaCol:= pos.col - 1;
     DIR   : novaCol:= pos.col + 1;
   end; 
   if (novaLin >= 1) and (novaLin <= j.nLin) and
      (novaCol >= 1) and (novaCol <= j.nCol) then
   begin
      pos.lin:= novaLin;
      pos.col:= novaCol;
   end;
end; { movePosicao }

procedure marcaPosicao(var j : TpJogo; pos: TpPosicao );
begin
   j.m[pos.lin, pos.col].marcado:= not j.m[pos.lin, pos.col].marcado;
end; { marcaPosicao }

function abreCelula(var j : TpJogo; pos: TpPosicao ): integer;
var
   l, c, cont : integer;
   p	      : TpPilha;
   cel	      : TpPosicao;
begin
   if j.m[pos.lin, pos.col].nBombas = VBOMBA then
      abreCelula:= 0
   else begin
      cont:= 1;
      j.m[pos.lin, pos.col].aberto:= true;
      j.m[pos.lin, pos.col].marcado:= false;
      if (j.m[pos.lin,pos.col].nBombas = 0) then
      begin
	 criaPilha( p );
	 empilha( p, pos );
	 while not pilhaVazia( p ) do
	 begin
	    desempilha( p, pos );
	    for l:=pos.lin-1 to pos.lin+1 do
	       for c:= pos.col-1 to pos.col+1 do
		  if (not j.m[l,c].aberto) and
		     (l >= 1) and (l <= j.nLin) and
		     (c >= 1) and (c <= j.nCol) then
		  begin
		     cont:= cont+1;
		     j.m[l,c].aberto:= true;
		     j.m[l,c].marcado:= false;
		     if (j.m[l,c].nBombas = 0) then
		     begin
			cel.lin:= l;
			cel.col:= c;
			empilha( p, cel );
		     end;
		  end;
	 end;
      end;
      abreCelula:= cont;
   end;
end; { abreCelula }

			     
(*-----------------------------------------------------------------------
 Programa principal
*)

begin
   criaJogo( j, pos );
   celParaAbrir:= j.nLin * j.nCol - j.nBombas;
   perdeu:= false;
   sair:= false;
   REPEAT
      mostraJogo ( j, pos );
      delay(ESPERA);
      ch:= leEntrada();
      if ch = FIM then
	 sair:= true
      else if ch = MARCA then
	 marcaPosicao( j, pos )
      else if (ch = ENTER) then
      begin
	 if posFechada( j, pos ) then
	 begin
	    nCelAberto := abreCelula(j, pos );
	    celParaAbrir:= celParaAbrir - nCelAberto;
	    if nCelAberto = 0 then
	       perdeu:= true;
	 end
      end
      else
	 movePosicao(ch, j, pos);
   UNTIL sair or perdeu or (celParaAbrir = 0);
   abreTudo( j );
   pos.lin:= 0; pos.col:= 0;
   mostraJogo( j, pos );
   writeln;
   if celParaAbrir = 0 then
      writeln('Parabens!! Voce venceu!!')
   else if nCelAberto = 0 then
      writeln('Voce perdeu...');
end.

