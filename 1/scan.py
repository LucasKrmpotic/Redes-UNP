
import netifaces
import nmap

def main():
    # Obteniendo ip del host
    ip = netifaces.ifaddresses('wlp2s0')[netifaces.AF_INET][0]['addr']

    # Instanciamos un objeto nm
    nmScan = nmap.PortScanner()

    # SCAN!
    result = nmScan.scan(ip, arguments="-sT -O -sV")

    print(result)

main()