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

sha512sums=("e8d47f9868f90651e4bf87c0a19653ff8b173cabbfec66004148a5a1ac9ea807fd949d2bf0db83ff3d2a7bab07fdb2c09d5c30d17b44caf6d9065696cf21f6ff")

package() {
	echo "heap-pair template class for C++."
	mkdir -p "${pkgdir}/usr/include/openutils/heap-pair"
	cp "${srcdir}/heap-pair.hh" "${pkgdir}/usr/include/openutils/heap-pair/heap-pair.hh"
	echo "Done!"
}
