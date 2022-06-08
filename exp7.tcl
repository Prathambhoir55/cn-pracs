# Create simulator object
set ns [new Simulator] 

# Setting colors
$ns color 1 Blue
$ns color 2 Red

# Create trace file for logging purposes
set tracefile [open exp7.tr w]
$ns trace-all $tracefile

# Create nam file
set namfile [open exp7.nam w]
$ns namtrace-all $namfile

# Create nodes
set n0 [$ns node]
set n1 [$ns node]

# Create links
$ns duplex-link $n0 $n1 6Mb 10ms DropTail

# Creation of TCP Agent
set tcp [new Agent/TCP]
set sink [new Agent/TCPSink]
$tcp set class_ 2
$ns attach-agent $n0 $tcp
$ns attach-agent $n1 $sink
$ns connect $tcp $sink

# Creation of application FTP
set ftp [new Application/FTP]
$ftp attach-agent $tcp

# Start Traffic
$ns at 1.0 "$ftp start"
$ns at 4.0 "$ftp stop"
$ns at 5.0 "finish"

# Finish procedure
proc finish {} {
    global ns tracefile namfile
    $ns flush-trace
    close $tracefile
    close $namfile
    exec nam exp7.nam &
    exit 0
}

# Run the simulation
$ns run