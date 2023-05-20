pkgname="openutils-mthread"
pkgver="1.0.0"
pkgrel="1"
pkgdesc="MTHREAD : The Multi-Threading Library"
arch=("x86_64" "i686")
conflicts=('openutils-mthread')
depends=(gcc)
license=("GNU GPL v3.0")
source=("https://raw.githubusercontent.com/Dark-CodeX/mthread/main/mthread/mthread.hh")

sha512sums=("f5e652a0cdfcef2c6d835616884e90cd5198475111a746c0f5e72120cf98b748493cbf7fd114b162b67b110eb02e49c35579f6ca01f87f4e6119ebb948675a7f")

package() {
	echo "MTHREAD : The Multi-Threading Library"
	mkdir -p "${pkgdir}/usr/include/openutils/mthread"
	cp "${srcdir}/mthread.hh" "${pkgdir}/usr/include/openutils/mthread/mthread.hh"
	echo "Done!"
}
