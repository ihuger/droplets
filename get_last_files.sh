#/usr/bin/env sh
dir="/usr/local/sandai/flume-server/"

records[0]="$dir/logs/.config.tail"
paths[0]="$dir/format-logs/config_1"
tables[0]="blue_original_config_login"

paths[1]="$dir/format-logs/gateway-1/"
records[1]="$dir/logs/.gateway.client.tail"
tables[0]="blue_original_gateway_client_info"

paths[2]="$dir/format-logs/gateway-2/"
records[2]="$dir/logs/.gateway.upload.tail"
tables[2]="blue_original_gateway_upload_info"


logfile="$dir/logs/send-to-mysql.log"


mysqlconnt="mysql -h172.16.1.101 -uroot -psd-9898w blue_dcdn_stat"
for i in `seq 3`
do
        
        newfile=`ls -rt ${paths[$i]}|tail -1`
        read oldfile < ${records[$i]}
        find ${paths[$i]} -newer $oldfile -exec du -sh {}
        #$mysqlconnt &>>$logfile <<EOF
        #        LOAD DATA LOCAL INFILE \'$file\' INTO TABLE  $table;
        #EOF
done

cd $dir


