################################################################################
# Automatically-generated file. Do not edit!
################################################################################

C_FILES += "..\Libraries\BaseSw\iLLD\TC26B\Tricore\Dts\Std\IfxDts.c"
OBJ_FILES += "Libraries\BaseSw\iLLD\TC26B\Tricore\Dts\Std\IfxDts.o"
"Libraries\BaseSw\iLLD\TC26B\Tricore\Dts\Std\IfxDts.o" : "..\Libraries\BaseSw\iLLD\TC26B\Tricore\Dts\Std\IfxDts.c" "Libraries\BaseSw\iLLD\TC26B\Tricore\Dts\Std\.IfxDts.o.opt"
	@echo Compiling ${<F}
	@"${PRODDIR}\bin\cctc" -f "Libraries\BaseSw\iLLD\TC26B\Tricore\Dts\Std\.IfxDts.o.opt"

"Libraries\BaseSw\iLLD\TC26B\Tricore\Dts\Std\.IfxDts.o.opt" : .refresh
	@argfile "Libraries\BaseSw\iLLD\TC26B\Tricore\Dts\Std\.IfxDts.o.opt" -o "Libraries\BaseSw\iLLD\TC26B\Tricore\Dts\Std\IfxDts.o" "..\Libraries\BaseSw\iLLD\TC26B\Tricore\Dts\Std\IfxDts.c" -Ctc26x --lsl-core=vtc -t -I"G:\Hello_world\TC264\A\workspace\Sig0809" -Wa-H"sfr/regtc26x.def" -Wa-gAHLs --emit-locals=-equs,-symbols -Wa-Ogs -Wa--error-limit=42 -I"G:\Hello_world\TC264\A\workspace\Sig0809\CODE" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\_Build" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\_Impl" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\_Lib" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\_Lib\DataHandling" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\_Lib\InternalMux" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\_PinMap" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Asclin" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Asclin\Asc" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Asclin\Lin" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Asclin\Spi" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Asclin\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Ccu6" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Ccu6\Icu" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Ccu6\PwmBc" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Ccu6\PwmHl" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Ccu6\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Ccu6\Timer" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Ccu6\TimerWithTrigger" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Ccu6\TPwm" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Cif" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Cif\Cam" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Cif\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Cpu" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Cpu\CStart" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Cpu\Irq" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Cpu\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Cpu\Trap" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Dma" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Dma\Dma" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Dma\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Dsadc" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Dsadc\Dsadc" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Dsadc\Rdc" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Dsadc\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Dts" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Dts\Dts" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Dts\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Emem" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Emem\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Eray" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Eray\Eray" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Eray\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Eth" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Eth\Phy_Pef7071" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Eth\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Fce" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Fce\Crc" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Fce\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Fft" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Fft\Fft" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Fft\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Flash" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Flash\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Gpt12" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Gpt12\IncrEnc" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Gpt12\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm\Atom" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm\Atom\Pwm" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm\Atom\PwmHl" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm\Atom\Timer" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm\Tim" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm\Tim\In" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm\Tom" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm\Tom\Pwm" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm\Tom\PwmHl" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm\Tom\Timer" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Gtm\Trig" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Hssl" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Hssl\Hssl" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Hssl\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\I2c" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\I2c\I2c" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\I2c\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Iom" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Iom\Driver" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Iom\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Msc" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Msc\Msc" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Msc\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Mtu" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Mtu\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Multican" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Multican\Can" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Multican\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Port" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Port\Io" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Port\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Psi5" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Psi5\Psi5" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Psi5\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Psi5s" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Psi5s\Psi5s" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Psi5s\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Qspi" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Qspi\SpiMaster" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Qspi\SpiSlave" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Qspi\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Scu" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Scu\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Sent" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Sent\Sent" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Sent\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Smu" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Smu\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Src" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Src\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Stm" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Stm\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Stm\Timer" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Vadc" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Vadc\Adc" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\iLLD\TC26B\Tricore\Vadc\Std" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\Infra" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\Infra\Platform" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\Infra\Platform\Tricore" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\Infra\Platform\Tricore\Compilers" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\Infra\Sfr" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\Infra\Sfr\TC26B" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\Infra\Sfr\TC26B\_Reg" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\Service" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\BaseSw\Service\CpuGeneric" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\seekfree_libraries" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\seekfree_libraries\common" -I"G:\Hello_world\TC264\A\workspace\Sig0809\Libraries\seekfree_peripheral" -I"G:\Hello_world\TC264\A\workspace\Sig0809\USER" --iso=99 --language=-gcc,-volatile,+strings,-kanji --fp-model=3 --switch=auto --align=0 --default-near-size=0 --default-a0-size=0 --default-a1-size=0 -O0 --tradeoff=0 -g -Wc-wW557 --error-limit=42 --source -c --dep-file="Libraries\BaseSw\iLLD\TC26B\Tricore\Dts\Std\.IfxDts.o.d" -Wc--make-target="Libraries\BaseSw\iLLD\TC26B\Tricore\Dts\Std\IfxDts.o"
DEPENDENCY_FILES += "Libraries\BaseSw\iLLD\TC26B\Tricore\Dts\Std\.IfxDts.o.d"


GENERATED_FILES += "Libraries\BaseSw\iLLD\TC26B\Tricore\Dts\Std\IfxDts.o" "Libraries\BaseSw\iLLD\TC26B\Tricore\Dts\Std\.IfxDts.o.opt" "Libraries\BaseSw\iLLD\TC26B\Tricore\Dts\Std\.IfxDts.o.d" "Libraries\BaseSw\iLLD\TC26B\Tricore\Dts\Std\IfxDts.src" "Libraries\BaseSw\iLLD\TC26B\Tricore\Dts\Std\IfxDts.lst"