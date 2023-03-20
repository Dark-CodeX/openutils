pkgname="openutils-vector"
pkgver="1.6.2"
pkgrel="4"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('openutils-vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("11c79add1d7e28e543ed9ad13c92f69ebbc79fcd5449cee5a37a898dd96cd542d1ed8f228131267877df6f44fe1013504a09810b757860c6b17b69d1aab3dabd" "fbef1829c6de3c0b5ffad67066850cf24d6b0b70c6eb6884111f9e635718472695968c1d96a25b5c3b7374138d4cc7d626e709b97f03ed4b166800bba0df57ea")

package() {
	echo "Vectors in C language."
	mkdir -p "${pkgdir}/usr/include/openutils/vector"
	cp "${srcdir}/vector.h" "${pkgdir}/usr/include/openutils/vector/vector.h"
	cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/openutils/vector/vector.hh"
	echo "Done!"
}