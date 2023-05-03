pkgname="openutils-mthread"
pkgver="1.0.0"
pkgrel="1"
pkgdesc="MTHREAD : The Multi-Threading Library"
arch=("x86_64" "i686")
conflicts=('openutils-mthread')
depends=(gcc)
license=("GNU GPL v3.0")
source=("https://raw.githubusercontent.com/Dark-CodeX/mthread/main/mthread/mthread.hh")

sha512sums=("cf83e1357eefb8bdf1542850d66d8007d620e4050b5715dc83f4a921d36ce9ce47d0d13c5d85f2b0ff8318d2877eec2f63b931bd47417a81a538327af927da3e")

package() {
	echo "MTHREAD : The Multi-Threading Library"
	mkdir -p "${pkgdir}/usr/include/openutils/mthread"
	cp "${srcdir}/mthread.hh" "${pkgdir}/usr/include/openutils/mthread/mthread.hh"
	echo "Done!"
}
