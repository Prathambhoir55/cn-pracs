# Create simulator object
set ns [new Simulator]

# Create trace file for logging purposes
set tracefile [open exp9.tr w] 
$ns trace-all $tracefile

# Create nam file
set namfile [open exp9.nam w] 
$ns namtrace-all $namfile

# Create nodes
set n0 [$ns node] 
set n1 [$ns node]

$ns at 0.0 "$n0 label Sender" 
$ns at 0.0 "$n1 label Receiver"

# Create links
$ns duplex-link $n0 $n1 0.2Mb 200ms DropTail 

$ns duplex-link-op $n0 $n1 orient right

# Set Queue Size of link
$ns queue-limit $n0 $n1 10

Agent/TCP set nam_tracevar_ true

# Setup a TCP connection
set tcp [new Agent/TCP] 
set sink [new Agent/TCPSink] 
$tcp set window_ 1 
$tcp set maxcwnd_ 1 
$ns attach-agent $n0 $tcp
$ns attach-agent $n1 $sink
$ns connect $tcp $sink

# Setup a FTP over TCP connection
set ftp [new Application/FTP] 
$ftp attach-agent $tcp

$ns add-agent-trace $tcp tcp 
$ns monitor-agent-trace $tcp 
$tcp tracevar cwnd_

# Schedule events
$ns at 0.0 "$ns trace-annotate \"Stop and Wait with normal operation\""
$ns at 0.05 "$ns trace-annotate \"FTP starts at 0.1\""
$ns at 0.1 "$ftp start" 
$ns at 0.11 "$ns trace-annotate \"Send Packet_0\"" 
$ns at 0.35 "$ns trace-annotate \"Receive Ack_0\"" 
$ns at 0.56 "$ns trace-annotate \"Send Packet_1\"" 
$ns at 0.79 "$ns trace-annotate \"Receive Ack_1\"" 
$ns at 0.99 "$ns trace-annotate \"Send Packet_2\"" 
$ns at 1.23 "$ns trace-annotate \"Receive Ack_2  \"" 
$ns at 1.43 "$ns trace-annotate \"Send Packet_3\"" 
$ns at 1.67 "$ns trace-annotate \"Receive Ack_3\"" 
$ns at 1.88 "$ns trace-annotate \"Send Packet_4\"" 
$ns at 2.11 "$ns trace-annotate \"Receive Ack_4\"" 
$ns at 2.32 "$ns trace-annotate \"Send Packet_5\"" 
$ns at 2.55 "$ns trace-annotate \"Receive Ack_5    \"" 
$ns at 2.75 "$ns trace-annotate \"Send Packet_6\"" 
$ns at 2.99 "$ns trace-annotate \"Receive Ack_6\""
$ns at 3.1 "$ns trace-annotate \"FTP stops\""
$ns at 3.5 "finish"

# Define a 'finish' procedure
proc finish {} { 
    global ns namfile tracefile
    $ns flush-trace
    close $tracefile
    close $namfile
    exec nam exp9.nam &
    exit 0 
}

$ns run