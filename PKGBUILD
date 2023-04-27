pkgname="openutils-vector"
pkgver="2.0.0"
pkgrel="4"
pkgdesc="VECTOR : The Resizable Array Library"
arch=("x86_64" "i686")
conflicts=('openutils-vector')
depends=(gcc)
license=("BSD 3-Clause License")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("3675fe3af18a5b1c2d1954a9e76285e35a471d79ca696708d4fad0878c4b05909f2d247c53004ba2b0adab451ecc3ece5f9c493c00c57fd7ac898482ba66c918")

package() {
	echo "VECTOR : The Resizable Array Library"
	mkdir -p "${pkgdir}/usr/include/openutils/vector"
	cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/openutils/vector/vector.hh"
	echo "Done!"
}