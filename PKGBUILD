pkgname="openutils-heap_pair"
pkgver="1.2.0"
pkgrel="1"
pkgdesc="HEAP-PAIR : The Pair Management Library"
arch=("x86_64" "i686")
conflicts=('openutils-heap_pair')
depends=(gcc)
license=("BSD 3-Clause License")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/heap-pair/main/heap-pair/heap-pair.hh")

sha512sums=("3680076f4d2b84c954eeabe4fc87471f705f8d68b1a8189e6b20dde92b91171e27de75fe435511ae120e2fee8cf12304898f142b81c61e5a72881e92ada95f04")

package() {
	echo "HEAP-PAIR : The Pair Management Library"
	mkdir -p "${pkgdir}/usr/include/openutils/heap-pair"
	cp "${srcdir}/heap-pair.hh" "${pkgdir}/usr/include/openutils/heap-pair/heap-pair.hh"
	echo "Done!"
}
