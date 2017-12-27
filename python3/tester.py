import speedtest, time;

#interval of 30 sec
INTERVAL = 30;

servers = [];

s = speedtest.Speedtest();

while(True):
    s.get_servers(servers);
    s.get_best_server();

    #setup the text to write to the file
    text = "";
    text += str(s.download() / 1000000) + "\n";
    text += str(s.upload() / 1000000) + "\n";

    #open a file to write to
    file = open("data.txt", "w");
    file.write(text);
    file.close();

    time.sleep(INTERVAL);