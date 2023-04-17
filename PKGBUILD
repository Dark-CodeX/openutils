pkgname="openutils-heap_pair"
pkgver="1.2.0"
pkgrel="1"
pkgdesc="heap-pair template class for C++."
arch=("x86_64" "i686")
conflicts=('openutils-heap_pair')
depends=(gcc)
license=("BSD 3-Clause License")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/heap-pair/main/heap-pair/heap-pair.hh")

sha512sums=("08bcd1d28f2e5387aa09dd99f5d1d694640c6ff709f3416624f86514e2c9a39b4cf3d3a6dfe79e6b362ee624faea05eb67d2ccd5ed48bdfc3bf1865bd4cf54fc")

package() {
	echo "heap-pair template class for C++."
	mkdir -p "${pkgdir}/usr/include/openutils/heap-pair"
	cp "${srcdir}/heap-pair.hh" "${pkgdir}/usr/include/openutils/heap-pair/heap-pair.hh"
	echo "Done!"
}
