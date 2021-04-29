telegraf &
echo "admin" >> /etc/vsftpd/vsftpd.userlist
echo	START FTPS
/usr/sbin/vsftpd /etc/vsftpd/vsftpd.conf