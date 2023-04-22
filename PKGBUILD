pkgname="openutils-vector"
pkgver="2.0.0"
pkgrel="4"
pkgdesc="VECTOR : The Resizable Array Library"
arch=("x86_64" "i686")
conflicts=('openutils-vector')
depends=(gcc)
license=("BSD 3-Clause License")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("41ba12bf2cd7a91bf8180934f1412ac082f0c8b271ec96e443c16d8f855eae0b301239189250fa1efa40ba40a31c294a8e7b54c7f158cd8b21cac286dd84d8db")

package() {
	echo "VECTOR : The Resizable Array Library"
	mkdir -p "${pkgdir}/usr/include/openutils/vector"
	cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/openutils/vector/vector.hh"
	echo "Done!"
}