local text = "abcdefghijklmnopqrstuvwxyz!?., "
--            1234567890123456789012345678901
local chars = {};
local i = 1;
--local message = "8 5 12 12 15 30 31 23 15 18 12 4 27";
--                 h e l  l  o  ,  |  w  o  r  l  d !      '|' - is a blank
--local message = "27 4 12 18 15 23 31 30 15 12 12 5 8";
--                 !  d l  r  o  w  |  ,  o  l  l  e h
local message =   "72 4 21 81 51 32 13 03 51 21 21 5 8"; --'hello, world!'

--separating the chars into an array
for char in text:gmatch( '.' ) do
	chars[ i ] = char;
	i = i + 1;
end

--stl does not work i dunno why so i created my own that works
function reverse( s )
	local r = ""
	for i = 1, #s, 1 do
		r = s:sub( i, i ) .. r
	end
	return r
end

--getting the message, convert it and print it
function print_crypt( s ) 
	--getting the message
	s = reverse( s );
	local ss = "";
	
	--convert the message
	for d in s:gmatch( '[^%s]+' ) do
		i = tonumber( d );
		ss = ss .. chars[ i ];
	end
	s = ss;
	
	--self-explanatory
	print( s );
end

print_crypt( message )
--after all of this, you can add even more characters 
--to the string text and use those characters as well!
--enjoy to use it!
