pkgname="openutils-optional"
pkgver="1.6.0"
pkgrel="2"
pkgdesc="OPTIONAL : The Error Handling Library"
arch=("x86_64" "i686")
conflicts=('openutils-optional')
depends=(gcc)
license=("BSD 3-Clause License")
source=("https://raw.githubusercontent.com/Dark-CodeX/optional/master/optional/optional.hh")

sha512sums=("a7ec6491c7b2c9e406dfb0f6ada331f0ec43c4f11865a4ac905be770f855e84bb7ba07b2e68aa21e739941790d95caa883265d95f4ae0b58bece648eba75c98f")

package() {
	echo "OPTIONAL : The Error Handling Library"
	mkdir -p "${pkgdir}/usr/include/openutils/optional"
	cp "${srcdir}/optional.hh" "${pkgdir}/usr/include/openutils/optional/optional.hh"
	echo "Done!"
}
