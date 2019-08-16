@echo off
for /f "delims=" %%a in ('dir /b/s/ad obj *.usr')do rd /s /q "%%a" 2>nul
del /a /f /s /q *.user 2>nul
pause