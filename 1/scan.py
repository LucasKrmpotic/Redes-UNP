
import netifaces
import nmap

def main():
    # Obteniendo ip del host
    ip = netifaces.ifaddresses('wlan0')[netifaces.AF_INET][0]['addr']

    # Instanciamos un objeto nm
    nmScan = nmap.PortScanner()

    # SCAN!
    result = nmScan.scan(ip, arguments="-sT -O -sV", callback=mifuncion)

    print(result)