pkgname="openutils-heap_pair"
pkgver="1.0.1"
pkgrel="1"
pkgdesc="heap-pair template class for C++."
arch=("x86_64" "i686")
conflicts=('openutils-heap_pair')
depends=(gcc)
license=("BSD 3-Clause License")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/heap-pair/main/heap-pair/heap-pair.hh")

sha512sums=("2556348d927e5b192f7936cdc8c82391277889e2a366298f11453446875edaec659de8d04ebf8ea20682321c156a12c36cc8495421e5ff877407bce62e0d055a")

package() {
	echo "heap-pair template class for C++."
	mkdir -p "${pkgdir}/usr/include/openutils/heap-pair"
	cp "${srcdir}/heap-pair.hh" "${pkgdir}/usr/include/openutils/heap-pair/heap-pair.hh"
	echo "Done!"
}
