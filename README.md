Every Drop Counts

### kerberos
With [Kerberos](https://kb.iu.edu/d/acjj), by exchanging time-sensitive tickets, you can make transactions secure without sending passwords in plaintext over the network.
A [keytab](https://kb.iu.edu/d/aumh) is a file containing pairs of Kerberos principals and encrypted keys (these are derived from the Kerberos password). You can use this file to log into Kerberos without being prompted for a password. The most common personal use of keytab files is to allow scripts to authenticate to Kerberos without human interaction, or store a password in a plaintext file. 
1. [keytab](https://kb.iu.edu/d/aumh)
2. [keylist](http://docs.oracle.com/javase/7/docs/technotes/tools/windows/klist.html)
3. [kinit](http://www.lehman.cuny.edu/cgi-bin/man-cgi?kinit+1)
4. NOTES:
    
    klist     #查看当前的keytab
    klist -l  #list keytab
    klist -k -t -K dcdn.keytab  #查看keytab内容
    kinit dcdn/user -k -t dcdn.keytab  #使用keytab

