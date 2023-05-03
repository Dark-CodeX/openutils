pkgname="openutils-heap_pair"
pkgver="1.2.0"
pkgrel="1"
pkgdesc="HEAP-PAIR : The Pair Management Library"
arch=("x86_64" "i686")
conflicts=('openutils-heap_pair')
depends=(gcc)
license=("GNU GPL v3.0")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/heap-pair/main/heap-pair/heap-pair.hh")

sha512sums=("2176fb586c91da56348d1030671425789955b69d6bfe3f25d6df66f81a33e0b76581d1cb152e3175581289c28a8cff8d4c5f450854be01ae0307412c03bb22d1")

package() {
	echo "HEAP-PAIR : The Pair Management Library"
	mkdir -p "${pkgdir}/usr/include/openutils/heap-pair"
	cp "${srcdir}/heap-pair.hh" "${pkgdir}/usr/include/openutils/heap-pair/heap-pair.hh"
	echo "Done!"
}
