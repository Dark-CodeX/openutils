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

sha512sums=("23e6c5e01922aad325b3e4c1cf4c6b2c22b775f148a475a2bcfdd6d4ebac85f3f971369d6ef39b7698afa7c3ddd39338ded1a3060707f28d2f11dca034afa5bb")

package() {
	echo "heap-pair template class for C++."
	mkdir -p "${pkgdir}/usr/include/openutils/heap-pair"
	cp "${srcdir}/heap-pair.hh" "${pkgdir}/usr/include/openutils/heap-pair/heap-pair.hh"
	echo "Done!"
}
