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

sha512sums=("51560f1406dab2d4bb5e02456543c3b1b6feb541802e0f184f13e98084fe192aa615724b6ce9bfca3d47bffcebd419c62e5da73628601504869a878a16ed54a1")

package() {
	echo "heap-pair template class for C++."
	mkdir -p "${pkgdir}/usr/include/openutils/heap-pair"
	cp "${srcdir}/heap-pair.hh" "${pkgdir}/usr/include/openutils/heap-pair/heap-pair.hh"
	echo "Done!"
}
