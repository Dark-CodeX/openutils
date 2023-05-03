pkgname="openutils-date_time"
pkgver="1.1.0"
pkgrel="1"
pkgdesc="DATE-TIME : The Date/Time Management Library"
arch=("x86_64" "i686")
conflicts=('openutils-date_time')
depends=(gcc)
license=("GNU GPL v3.0")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/date-time/main/date-time/date.hh"
	"https://raw.githubusercontent.com/Dark-CodeX/date-time/main/date-time/time.hh")

sha512sums=(
	"3258442c155bc392ca1e6a48e95761dc181996689e5917daa73d53100c71cc8e70e84affba799b17c1db2c1b6cea798acc6885a118e843f49f9b51dcafbedcf3"
	"44ff193040bb4a2ee0620d2ba0cc5f53987c1bacd958cc940694816c12fae9104a265c249496fcbf4fcd26c7d2afa07ac50076f4736a4e31ce5b736b59343c49")

package() {
	echo "DATE-TIME : The Date/Time Management Library"
	mkdir -p "${pkgdir}/usr/include/openutils/date-time"
	cp "${srcdir}/date.hh" "${pkgdir}/usr/include/openutils/date-time/date.hh"
	cp "${srcdir}/time.hh" "${pkgdir}/usr/include/openutils/date-time/time.hh"
	echo "Done!"
}
