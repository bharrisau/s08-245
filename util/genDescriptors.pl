use USB::Descriptor;
# use Unicode::String qw(utf8 latin1 utf16le);
use Encode;
 
my $device = USB::Descriptor::device(
    'usb_version'       => '1.1.0',         # Default
    'class'             => 0,
    'max_packet_size'   => 8,              # Full speed device
    'vendorID'          => 0x1d50,
    'productID'         => 0xAAAA,
    'version'           => '0.1.0',
    'manufacturer'      => 'bharr',
    'product'           => 'S08JS JTAG-Bridge',
    #'serial_number'     => '007',         # Later make a placeholder
    'configurations'    => [{
        #'description'   => 'Default',      # Really needed?
        'value'             => 1,
        'remote_wakeup'     => 0,
        'self_powered'      => 0,
        'max_current'       => 500,   # mA
        # 'interfaces'        => [{         #Only EP0
        #     #'description'       => 'Interface 0',
        #     'endpoints'         => [{
        #         'direction'         => 'in',
        #         'number'            => 1,
        #         'max_packet_size'   => 42,
        #     }]
        # }]
    }]
);

my @bytes = @{$device};
print '/*@unused@*/ static const byte device_descriptor[] = {', join(', ', @bytes), "};\n";

my @configurations = @{$device->configurations};
foreach my $configuration ( @configurations )
{
    print '/*@unused@*/ static const byte configuration[] = {',
            join(', ', @{$configuration->bytes} ), "};\n";
}

print '/*@unused@*/ static const byte string0[] = {4, 3, 9, 4};', "\n";
my @strings = $device->strings;
my $i = 1;
foreach my $string ( @strings )
{
    my $u = encode("UTF-16LE", $string);
    my @stt = map {sprintf("%d",ord)} split(//, $u);
    print '/*@unused@*/ static const byte string', $i, '[] = {',
        (scalar @stt)+2, ", 3, ",
        join(", ", @stt)
        , "};\n";
    $i++;
}
$i = 1;
print '/*@unused@*/ static const byte *strings[] = { string0, ',
    join(', ',map {sprintf("string%d",$i++)} @strings),
    "};\n"


