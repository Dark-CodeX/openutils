pkgname="openutils-heap_pair"
pkgver="1.0.0"
pkgrel="1"
pkgdesc="heap-pair template class for C++."
arch=("x86_64" "i686")
conflicts=('openutils-heap_pair')
depends=(gcc)
license=("MIT")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/heap-pair/main/heap-pair/heap-pair.hh")

sha512sums=(
	"48d8db39a71d3e8c44667a6619a581f73926f3b5962d2165ea927b37bf8b5d1b6ac5996d1e9aadae53dbc8bef051223062596d61c6397fd3730c015ef563b649")

package() {
	echo "heap-pair template class for C++."
	mkdir -p "${pkgdir}/usr/include/openutils/heap-pair"
	cp "${srcdir}/heap-pair.hh" "${pkgdir}/usr/include/openutils/heap-pair/heap-pair.hh"
	echo "Done!"
}
