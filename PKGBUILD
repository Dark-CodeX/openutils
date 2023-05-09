pkgname="openutils-mthread"
pkgver="1.0.0"
pkgrel="1"
pkgdesc="MTHREAD : The Multi-Threading Library"
arch=("x86_64" "i686")
conflicts=('openutils-mthread')
depends=(gcc)
license=("GNU GPL v3.0")
source=("https://raw.githubusercontent.com/Dark-CodeX/mthread/main/mthread/mthread.hh")

sha512sums=("3539f7bec51d080c56011a5668fc007e0f7eed2d67f72c66d1a2151c276e94cab41cd0e9b221db96cea0fb6c3ec7d96f0e4b55fff5458189910053bb4e0ed09e")

package() {
	echo "MTHREAD : The Multi-Threading Library"
	mkdir -p "${pkgdir}/usr/include/openutils/mthread"
	cp "${srcdir}/mthread.hh" "${pkgdir}/usr/include/openutils/mthread/mthread.hh"
	echo "Done!"
}
